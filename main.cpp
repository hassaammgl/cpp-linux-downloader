// #include <iostream>
// #include <cstdlib>

// using namespace std;

// class Utils
// {
// public:
//     void runner(string cmd, string ok, string err)
//     {
//         string command = cmd;
//         int result = system(command.c_str());
//         cout << "result: " << result << endl;
//         if (result == 0)
//         {
//             cout << ok << endl;
//         }
//         else
//         {
//             cerr << err << endl;
//         }
//     }

//     void checkingAndInstallLibsAndUpdateLibs()
//     {
//         bool ans;
//         cout << "Checking Libs ...." << endl;
//         runner("ffmpeg -version > /dev/null 2>&1", "Ffmpeg is installed....", "ffmpeg is not installed....");
//         runner("yt-dlp -v > /dev/null 2>&1", "yt-dlp is installed....", "yt-dlp is not installed....");
//         // runner("sudo apt update && sudo apt install yt-dlp -y", "", "");

//         cout << "Do you want to install libs for it.... 1 for (yes), 0 for (no):" << endl;
//         cin >> ans;
//         if (ans == true)
//         {
//             runner("sudo apt update -y", "all packages are updated", "error while updating....");
//             runner("sudo apt install yt-dlp -y", "yt-dlp is installed....", "yt-dlp is not installed....");
//             runner("sudo apt install ffmpeg -y", "ffmpeg is installed....", "ffmpeg is not installed....");
//         }
//         else
//         {
//             exit(1);
//         }
//     }
// };

// class Downloaders
// {
// public:
//     void downloadOneAudio(const string &url, const string &outputFile = "audio.mp3")
//     {
//         string command = "yt-dlp -f 'bestaudio' --extract-audio --audio-format mp3 -o '" + outputFile + "' " + url;
//         int result = system(command.c_str());

//         if (result == 0)
//         {
//             cout << "Audio downloaded successfully: " << outputFile << "\n";
//         }
//         else
//         {
//             cerr << "Failed to download audio! Make sure yt-dlp is installed.\n";
//         }
//     }

//     void downloadPlaylistAudio(const string &playlistUrl, const string &outputFolder = "Playlist_Audio")
//     {
//         string command = "mkdir -p '" + outputFolder + "' && yt-dlp -f 'bestaudio' --extract-audio --audio-format mp3 -o '" + outputFolder + "/%(title)s.%(ext)s' " + playlistUrl;
//         int result = system(command.c_str());

//         if (result == 0)
//         {
//             cout << "Playlist audio downloaded successfully in folder: " << outputFolder << "\n";
//         }
//         else
//         {
//             cerr << "Failed to download playlist audio! Make sure yt-dlp is installed.\n";
//         }
//     }

//     void downloadVideo(const string &url)
//     {
//         string command = "yt-dlp " + url;
//         int result = system(command.c_str());

//         if (result == 0)
//         {
//             cout << "Download successful!\n";
//         }
//         else
//         {
//             cerr << "Download failed! Make sure yt-dlp is installed.\n";
//         }
//     }

//     void downloadPlaylistVideos(const string &playlistUrl, const string &outputFolder = "Playlist_Videos")
//     {
//         string command = "mkdir -p '" + outputFolder + "' && yt-dlp -f 'best' -o '" + outputFolder + "/%(title)s.%(ext)s' " + playlistUrl;
//         int result = system(command.c_str());

//         if (result == 0)
//         {
//             cout << "Playlist videos downloaded successfully in folder: " << outputFolder << "\n";
//         }
//         else
//         {
//             cerr << "Failed to download playlist videos! Make sure yt-dlp is installed.\n";
//         }
//     }
// };

// int main()
// {
//     Utils ut;
//     ut.checkingAndInstallLibsAndUpdateLibs();

//     string videoUrl;
//     int choice;

//     cout << "Do you want to download vid or aud [1/2]" << endl;
//     cin >> choice;
//     switch (choice)
//     {
//     case 1:
//         cout << "To Download Playlist or single vid [1/2]" << endl;
//         cin >> choice;
//         break;
//     case 2:
//         cout << "To Download Playlist or single aud [1/2]" << endl;
//         cin >> choice;
//         break;
//     default:
//         cout << "invalid choice" << endl;
//         break;
//     }

//     // cout << "Enter YouTube video URL: ";
//     // getline(cin, videoUrl);

//     // if (!videoUrl.empty())
//     // {
//     //     downloadVideo(videoUrl);
//     // }
//     // else
//     // {
//     //     cerr << "Invalid URL!\n";
//     // }

//     return 0;
// }

// #include <iostream>
// #include <cstdlib>

// using namespace std;

// class Utils {
// public:
//     void runCommand(const string &cmd, const string &successMsg, const string &errorMsg) {
//         if (system(cmd.c_str()) == 0) {
//             cout << successMsg << endl;
//         } else {
//             cerr << errorMsg << endl;
//         }
//     }

//     void checkAndInstallDependencies() {
//         cout << "Checking dependencies...\n";

//         bool needInstall = false;
//         if (system("ffmpeg -version > /dev/null 2>&1") != 0) {
//             cerr << "ffmpeg is not installed.\n";
//             needInstall = true;
//         } else {
//             cout << "ffmpeg is installed.\n";
//         }

//         if (system("yt-dlp -v > /dev/null 2>&1") != 0) {
//             cerr << "yt-dlp is not installed.\n";
//             needInstall = true;
//         } else {
//             cout << "yt-dlp is installed.\n";
//         }

//         if (needInstall) {
//             cout << "Do you want to install missing dependencies? (1 for Yes, 0 for No): ";
//             int choice;
//             cin >> choice;

//             if (choice == 1) {
//                 runCommand("sudo apt update -y", "System updated.", "Error updating system.");
//                 runCommand("sudo apt install yt-dlp -y", "yt-dlp installed.", "Error installing yt-dlp.");
//                 runCommand("sudo apt install ffmpeg -y", "ffmpeg installed.", "Error installing ffmpeg.");
//             } else {
//                 cout << "Dependencies are required for this program. Exiting...\n";
//                 exit(1);
//             }
//         }
//     }
// };

// class Downloaders {
// public:
//     void downloadAudio(const string &url, const string &outputPath = "audio.mp3") {
//         string command = "yt-dlp -f 'bestaudio' --extract-audio --audio-format mp3 -o '" + outputPath + "' " + url;
//         runDownload(command, "Audio downloaded successfully: " + outputPath);
//     }

//     void downloadPlaylistAudio(const string &playlistUrl, const string &outputFolder = "Playlist_Audio") {
//         string command = "mkdir -p '" + outputFolder + "' && yt-dlp -f 'bestaudio' --extract-audio --audio-format mp3 -o '" + outputFolder + "/%(title)s.%(ext)s' " + playlistUrl;
//         runDownload(command, "Playlist audio downloaded successfully in: " + outputFolder);
//     }

//     void downloadVideo(const string &url, const string &outputPath = "video.mp4") {
//         string command = "yt-dlp -o '" + outputPath + "' " + url;
//         runDownload(command, "Video downloaded successfully: " + outputPath);
//     }

//     void downloadPlaylistVideos(const string &playlistUrl, const string &outputFolder = "Playlist_Videos") {
//         string command = "mkdir -p '" + outputFolder + "' && yt-dlp -f 'best' -o '" + outputFolder + "/%(title)s.%(ext)s' " + playlistUrl;
//         runDownload(command, "Playlist videos downloaded successfully in: " + outputFolder);
//     }

// private:
//     void runDownload(const string &command, const string &successMsg) {
//         if (system(command.c_str()) == 0) {
//             cout << successMsg << endl;
//         } else {
//             cerr << "Download failed! Ensure yt-dlp is installed.\n";
//         }
//     }
// };

// int main() {
//     Utils utils;
//     utils.checkAndInstallDependencies();

//     Downloaders downloader;
//     int mainChoice, subChoice;
//     string url, outputPath;

//     cout << "Choose an option:\n";
//     cout << "1. Download Video\n";
//     cout << "2. Download Audio\n";
//     cout << "Enter your choice: ";
//     cin >> mainChoice;

//     cout << "Download single file or playlist?\n";
//     cout << "1. Single\n";
//     cout << "2. Playlist\n";
//     cout << "Enter your choice: ";
//     cin >> subChoice;

//     cin.ignore(); // Clear input buffer
//     cout << "Enter the YouTube URL: ";
//     getline(cin, url);

//     cout << "Enter output folder (or press Enter for default): ";
//     getline(cin, outputPath);

//     if (outputPath.empty()) {
//         outputPath = (mainChoice == 1) ? "video.mp4" : "audio.mp3";
//     }

//     if (mainChoice == 1) {
//         if (subChoice == 1) {
//             downloader.downloadVideo(url, outputPath);
//         } else {
//             downloader.downloadPlaylistVideos(url, outputPath);
//         }
//     } else if (mainChoice == 2) {
//         if (subChoice == 1) {
//             downloader.downloadAudio(url, outputPath);
//         } else {
//             downloader.downloadPlaylistAudio(url, outputPath);
//         }
//     } else {
//         cout << "Invalid choice! Exiting...\n";
//         return 1;
//     }

//     return 0;
// }

#include <iostream>
#include <cstdlib>

using namespace std;

class Utils
{
public:
    void runCommand(const string &cmd, const string &successMsg, const string &errorMsg)
    {
        int result = system(cmd.c_str());
        if (result == 0)
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

        runCommand("ffmpeg -version > /dev/null 2>&1", "ffmpeg is installed.", "ffmpeg is not installed.");
        runCommand("yt-dlp -v > /dev/null 2>&1", "yt-dlp is installed.", "yt-dlp is not installed.");

        cout << "Do you want to install missing dependencies? (1 for Yes, 0 for No): ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            runCommand("sudo apt update -y", "System updated.", "Failed to update system.");
            runCommand("sudo apt install yt-dlp -y", "yt-dlp installed.", "Failed to install yt-dlp.");
            runCommand("sudo apt install ffmpeg -y", "ffmpeg installed.", "Failed to install ffmpeg.");
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
    void downloadAudio(const string &url, const string &outputFolder = "./")
    {
        system(("mkdir -p '" + outputFolder + "'").c_str());

        string outputFile = outputFolder;
        if (outputFile.back() == '/')
        {
            outputFile += "%(title)s.%(ext)s";
        }

        string command = "yt-dlp -f 'bestaudio' --extract-audio --audio-format mp3 -o '" + outputFile + "' " + url;
        if (system(command.c_str()) == 0)
        {
            cout << "Audio downloaded successfully in: " << outputFolder << "\n";
        }
        else
        {
            cerr << "Failed to download audio! Ensure yt-dlp is installed.\n";
        }
    }

    void downloadPlaylistAudio(const string &playlistUrl, const string &outputFolder = "./Playlist_Audio/")
    {
        system(("mkdir -p '" + outputFolder + "'").c_str());

        string command = "yt-dlp -f 'bestaudio' --extract-audio --audio-format mp3 -o '" + outputFolder + "/%(title)s.%(ext)s' " + playlistUrl;
        if (system(command.c_str()) == 0)
        {
            cout << "Playlist audio downloaded successfully in: " << outputFolder << "\n";
        }
        else
        {
            cerr << "Failed to download playlist audio! Ensure yt-dlp is installed.\n";
        }
    }

    void downloadVideo(const string &url, const string &outputFolder = "./Videos/")
    {
        system(("mkdir -p '" + outputFolder + "'").c_str());

        string command = "yt-dlp -f 'best' -o '" + outputFolder + "/%(title)s.%(ext)s' " + url;
        if (system(command.c_str()) == 0)
        {
            cout << "Video downloaded successfully in: " << outputFolder << "\n";
        }
        else
        {
            cerr << "Failed to download video! Ensure yt-dlp is installed.\n";
        }
    }

    void downloadPlaylistVideos(const string &playlistUrl, const string &outputFolder = "./Playlist_Videos/")
    {
        system(("mkdir -p '" + outputFolder + "'").c_str());

        string command = "yt-dlp -f 'best' -o '" + outputFolder + "/%(title)s.%(ext)s' " + playlistUrl;
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
