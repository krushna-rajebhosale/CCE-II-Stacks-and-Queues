
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Node represents one song in the playlist
class Node {
public:
    string title;
    string artist;
    Node* prev;
    Node* next;

    Node(string t, string a) {
        title = t;
        artist = a;
        prev = nullptr;
        next = nullptr;
    }
};

class MusicPlaylist {
private:
    Node* head;
    Node* current;

public:
    MusicPlaylist() {
        head = nullptr;
        current = nullptr;
    }

    // 1. Add a song at the end
    void addSong(string title, string artist) {
        Node* p = new Node(title, artist);

        if (head == nullptr) {
            head = p;
            current = p;
        } else {
            Node* q = head;

            while (q->next != nullptr) {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
        }

        cout << "Song added successfully!\n";
    }

    // 2. Delete a song by title
    void deleteSong(string title) {
        Node* q = head;

        while (q != nullptr && q->title != title) {
            q = q->next;
        }

        if (q == nullptr) {
            cout << "Song not found!\n";
            return;
        }

        Node* p = q;
        Node* nextSong = p->next;

        if (p->prev != nullptr) {
            p->prev->next = p->next;
        } else {
            head = p->next;
        }

        if (p->next != nullptr) {
            p->next->prev = p->prev;
        }

        if (current == p) {
            if (nextSong != nullptr) {
                current = nextSong;
            } else {
                current = p->prev;
            }
        }

        delete p;
        cout << "Song deleted successfully!\n";
    }

    // 3. Display playlist from first to last
    void displayForward() {
        Node* q = head;

        if (q == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        cout << "\n--- Playlist (Forward) ---\n";

        while (q != nullptr) {
            cout << q->title << " - " << q->artist << "\n";
            q = q->next;
        }
    }

    // 4. Display playlist from last to first
    void displayBackward() {
        Node* q = head;

        if (q == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        while (q->next != nullptr) {
            q = q->next;
        }

        cout << "\n--- Playlist (Reverse) ---\n";

        while (q != nullptr) {
            cout << q->title << " - " << q->artist << "\n";
            q = q->prev;
        }
    }

    // 5. Play current song
    void playCurrentSong() {
        if (current == nullptr) {
            cout << "Playlist is empty!\n";
        } else {
            cout << "Playing: " << current->title
                 << " - " << current->artist << "\n";
        }
    }

    // 6. Play next song
    void playNextSong() {
        if (current == nullptr) {
            cout << "Playlist is empty!\n";
        } else if (current->next == nullptr) {
            cout << "Already at the last song!\n";
        } else {
            current = current->next;
            playCurrentSong();
        }
    }

    // 7. Play previous song
    void playPreviousSong() {
        if (current == nullptr) {
            cout << "Playlist is empty!\n";
        } else if (current->prev == nullptr) {
            cout << "Already at the first song!\n";
        } else {
            current = current->prev;
            playCurrentSong();
        }
    }

    // 8. Play all songs once
    void playCompletePlaylist() {
        Node* q = head;

        if (q == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        cout << "\n--- Playing Complete Playlist ---\n";

        while (q != nullptr) {
            cout << "Playing: " << q->title
                 << " - " << q->artist << "\n";
            q = q->next;
        }

        // Set current to the last song
        q = head;
        while (q->next != nullptr) {
            q = q->next;
        }
        current = q;
    }

    // 9. Repeat the complete playlist N times
    void repeatAll(int repetitions) {
        if (head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }

        if (repetitions <= 0) {
            cout << "Enter a number greater than zero!\n";
            return;
        }

        for (int i = 1; i <= repetitions; i++) {
            cout << "\nRepetition " << i << ":\n";

            Node* q = head;
            current = head;

            while (q != nullptr) {
                cout << "Playing: " << q->title
                     << " - " << q->artist << "\n";

                current = q;
                q = q->next;
            }
        }

        cout << "Repeat completed!\n";
    }

    // 10. Show the current song
    void showCurrentSong() {
        if (current == nullptr) {
            cout << "No song selected!\n";
        } else {
            cout << "Current Song: " << current->title
                 << " - " << current->artist << "\n";
        }
    }

    // Release all dynamically allocated nodes
    ~MusicPlaylist() {
        Node* q = head;

        while (q != nullptr) {
            Node* p = q;
            q = q->next;
            delete p;
        }
    }
};

int main() {
    MusicPlaylist playlist;
    int choice;
    string title, artist;

    do {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Display Playlist in Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All N Times\n";
        cout << "10. Show Current Song\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );
            continue;
        }

        cin.ignore(
            numeric_limits<streamsize>::max(), '\n'
        );

        switch (choice) {
        case 1:
            cout << "Enter song title: ";
            getline(cin, title);

            cout << "Enter artist name: ";
            getline(cin, artist);

            playlist.addSong(title, artist);
            break;

        case 2:
            cout << "Enter title to delete: ";
            getline(cin, title);

            playlist.deleteSong(title);
            break;

        case 3:
            playlist.displayForward();
            break;

        case 4:
            playlist.displayBackward();
            break;

        case 5:
            playlist.playCurrentSong();
            break;

        case 6:
            playlist.playNextSong();
            break;

        case 7:
            playlist.playPreviousSong();
            break;

        case 8:
            playlist.playCompletePlaylist();
            break;

        case 9: {
            int repetitions;

            cout << "Enter number of repetitions: ";

            if (!(cin >> repetitions)) {
                cout << "Invalid repetition count!\n";
                cin.clear();
                cin.ignore(
                    numeric_limits<streamsize>::max(), '\n'
                );
                break;
            }

            cin.ignore(
                numeric_limits<streamsize>::max(), '\n'
            );

            playlist.repeatAll(repetitions);
            break;
        }

        case 10:
            playlist.showCurrentSong();
            break;

        case 11:
            cout << "Exiting Music Playlist Manager.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 11);

    return 0;
}
