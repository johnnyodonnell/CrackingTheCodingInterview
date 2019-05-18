#include <vector>


class Call {
    public:
        void hold();
        void resume();
};

class Employee {
    public:
        virtual bool is_available() = 0;
        virtual void handle_call(Call&) = 0;
};

class Director : public Employee {
};

class Manager : public Employee {
    private:
        const Director& director;
        void escalateCall();

    public:
        Manager(const Director&);
};

class Respondent : public Employee {
    private:
        const Manager& manager;
        void escalateCall();

    public:
        Respondent(const Manager&);
};

class CallCenter {
    private:
        std::vector<Respondent> respondents;
        void dispatchCall();

    public:
        void queueCall(Call&);
};

