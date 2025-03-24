#include <iostream>
#include <cstdlib>

class PackageChecker {
public:
    bool isInstalled(const std::string& command) {
        return system(("which " + command + " > /dev/null 2>&1").c_str()) == 0;
    }

    void installPackage(const std::string& package) {
        std::cout << "Installing " << package << "...\n";
        system(("sudo apt update && sudo apt install -y " + package).c_str());
    }
};

class Program {
private:
    PackageChecker checker;

    bool tryDownload(const std::string& command) {
        int result = system(command.c_str());
        return result == 0;
    }

public:
    void run() {
        bool ffmpegInstalled = checker.isInstalled("ffmpeg");
        bool ytdlpInstalled = checker.isInstalled("yt-dlp");

        if (ffmpegInstalled && ytdlpInstalled) {
            std::cout << "Both ffmpeg and yt-dlp are installed.\n";
        } else {
            std::cout << "One or both dependencies (ffmpeg, yt-dlp) are missing.\n";
            bool installDependencies;
            std::cout << "Do you want to install them? (1 for yes, 0 for no): ";
            std::cin >> installDependencies;

            if (installDependencies) {
                if (!ffmpegInstalled) checker.installPackage("ffmpeg");
                if (!ytdlpInstalled) checker.installPackage("yt-dlp");
            } else {
                std::cout << "Exiting program.\n";
                return;
            }
        }
        
        std::string outputFolder;
        std::cout << "Enter output folder path: ";
        std::cin >> outputFolder;
        
        bool downloadVideo;
        std::cout << "Do you want to download video? (1 for video, 0 for audio): ";
        std::cin >> downloadVideo;
        
        bool isPlaylist;
        std::cout << "Is this a single video or a playlist? (1 for playlist, 0 for single video): ";
        std::cin >> isPlaylist;
        
        std::string url;
        std::cout << "Enter the video or playlist URL: ";
        std::cin >> url;
        
        std::string format;
        
        if (isPlaylist) {
            std::cout << "Playlist detected. Only MP4 format will be used.\n";
            format = "mp4";
        } else {
            std::cout << "Fetching available formats...\n";
            system(("yt-dlp -F " + url).c_str());
            std::cout << "Enter the desired format code: ";
            std::cin >> format;
        }
        
        std::string command = "yt-dlp -f " + format + " -o '" + outputFolder + "/%(title)s.%(ext)s' " + url;
        
        if (downloadVideo) {
            std::cout << (isPlaylist ? "Downloading video playlist in MP4 format...\n" : "Downloading single video...\n");
        } else {
            std::cout << (isPlaylist ? "Downloading audio playlist...\n" : "Downloading single audio...\n");
            command += " --extract-audio";
        }
        
        while (!tryDownload(command)) {
            std::cout << "Download failed! Trying a different method...\n";
            command = "yt-dlp -f bestvideo+bestaudio --merge-output-format mp4 -o '" + outputFolder + "/%(title)s.%(ext)s' " + url;
        }
        
        std::cout << "Download complete!\n";
    }
};

int main() {
    Program program;
    program.run();
    return 0;
}
