#include <unordered_map>
#include <vector>


class Message {};

class Participant {};

class Chat {
    private:
        std::vector<Message> log;
        std::vector<Participant*> participants;

    public:
        void send_message(const Message&);
        std::vector<Message> display_message();
};

class ChatServer {
    private:
        std::unordered_map<int, Chat> chats;

    public:
        const Chat& subscribe(int id, const Participant&);
        void publish(int id, const Message&);
};

