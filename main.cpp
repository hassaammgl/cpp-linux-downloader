#include <iostream>
#include <cstdlib>

using namespace std;

class Utils
{
public:
    bool isInstalled(const string &cmd)
    {
        return system((cmd + " > /dev/null 2>&1").c_str()) == 0;
    }

    void runCommand(const string &cmd, const string &successMsg, const string &errorMsg)
    {
        if (system(cmd.c_str()) == 0)
        {
            cout << successMsg << endl;
        }
        else
        {
            cerr << errorMsg << endl;
        }
    }

    void checkAndInstallDependencies()
    {
        cout << "Checking dependencies...\n";

        bool ffmpegInstalled = isInstalled("ffmpeg -version");
        bool ytDlpInstalled = isInstalled("yt-dlp -v");

        if (ffmpegInstalled && ytDlpInstalled)
        {
            cout << "All dependencies are installed. Proceeding...\n";
            return;
        }

        cout << "Some dependencies are missing. Do you want to install them? (1 for Yes, 0 for No): ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            runCommand("sudo apt update -y", "System updated.", "Failed to update system.");

            if (!ytDlpInstalled)
            {
                runCommand("sudo apt install yt-dlp -y", "yt-dlp installed.", "Failed to install yt-dlp.");
            }

            if (!ffmpegInstalled)
            {
                runCommand("sudo apt install ffmpeg -y", "ffmpeg installed.", "Failed to install ffmpeg.");
            }
        }
        else
        {
            exit(1);
        }
    }
};

class Downloader
{
public:
    void downloadAudio(const string &url, const string &outputFolder = "~/Downloads/Audio/")
    {
        system(("mkdir -p '" + outputFolder + "'").c_str());

        string command = "yt-dlp -f 'bestaudio' --extract-audio --audio-format mp3 -o '" + outputFolder + "%(title)s.%(ext)s' " + url;
        if (system(command.c_str()) == 0)
        {
            cout << "Audio downloaded successfully in: " << outputFolder << "\n";
        }
        else
        {
            cerr << "Failed to download audio! Ensure yt-dlp is installed.\n";
        }
    }

    void downloadPlaylistAudio(const string &playlistUrl, const string &outputFolder = "~/Downloads/Playlist_Audio/")
    {
        system(("mkdir -p '" + outputFolder + "'").c_str());

        string command = "yt-dlp -f 'bestaudio' --extract-audio --audio-format mp3 -o '" + outputFolder + "%(title)s.%(ext)s' " + playlistUrl;
        if (system(command.c_str()) == 0)
        {
            cout << "Playlist audio downloaded successfully in: " << outputFolder << "\n";
        }
        else
        {
            cerr << "Failed to download playlist audio! Ensure yt-dlp is installed.\n";
        }
    }

    void downloadVideo(const string &url, const string &outputFolder = "~/Downloads/Videos/")
    {
        system(("mkdir -p '" + outputFolder + "'").c_str());

        string command = "yt-dlp -f 'best' -o '" + outputFolder + "%(title)s.%(ext)s' " + url;
        if (system(command.c_str()) == 0)
        {
            cout << "Video downloaded successfully in: " << outputFolder << "\n";
        }
        else
        {
            cerr << "Failed to download video! Ensure yt-dlp is installed.\n";
        }
    }

    void downloadPlaylistVideos(const string &playlistUrl, const string &outputFolder = "~/Downloads/Playlist_Videos/")
    {
        system(("mkdir -p '" + outputFolder + "'").c_str());

        string command = "yt-dlp -f 'best' -o '" + outputFolder + "%(title)s.%(ext)s' " + playlistUrl;
        if (system(command.c_str()) == 0)
        {
            cout << "Playlist videos downloaded successfully in: " << outputFolder << "\n";
        }
        else
        {
            cerr << "Failed to download playlist videos! Ensure yt-dlp is installed.\n";
        }
    }
};

int main()
{
    Utils utils;
    Downloader downloader;

    utils.checkAndInstallDependencies();

    int mainChoice, subChoice;
    string url, outputFolder;

    cout << "Choose an option:\n1. Download Video\n2. Download Audio\nEnter your choice: ";
    cin >> mainChoice;

    cout << "Download single file or playlist?\n1. Single\n2. Playlist\nEnter your choice: ";
    cin >> subChoice;

    cout << "Enter the YouTube URL: ";
    cin >> url;

    cout << "Enter output folder (or press Enter for default): ";
    cin.ignore();
    getline(cin, outputFolder);

    if (outputFolder.empty())
    {
        outputFolder = (mainChoice == 1) ? ((subChoice == 1) ? "~/Downloads/Videos/" : "~/Downloads/Playlist_Videos/")
                                         : ((subChoice == 1) ? "~/Downloads/Audio/" : "~/Downloads/Playlist_Audio/");
    }

    if (mainChoice == 1)
    {
        if (subChoice == 1)
            downloader.downloadVideo(url, outputFolder);
        else
            downloader.downloadPlaylistVideos(url, outputFolder);
    }
    else if (mainChoice == 2)
    {
        if (subChoice == 1)
            downloader.downloadAudio(url, outputFolder);
        else
            downloader.downloadPlaylistAudio(url, outputFolder);
    }
    else
    {
        cout << "Invalid choice!\n";
    }

    return 0;
}
