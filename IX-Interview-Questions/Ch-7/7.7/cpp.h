#include <unordered_map>
#include <vector>


class Message {};

class Chat {
    private:
        std::vector<Message> log;

    public:
        void send_message(const Message&);
        std::vector<Message> display_message();
};

class ChatServer {
    private:
        std::unordered_map<int, Chat> chats;

    public:
        const Chat& subscribe(int id);
        void publish(int id, const Message&);
};

