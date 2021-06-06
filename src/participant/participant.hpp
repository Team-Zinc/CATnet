/// \brief Participant class that contains all the data needed for runtime in case of participant mode.
class Participant {
public:
    /// \brief Constructor for the participant.
    /// If you need to pass in any arguments, please add them to the
    /// subcommand, and pass that in here. Do not pass them in individually.
    Participant();

    /// \brief Constructor for the participant.
    ~Participant();
    
    /// \brief Run the main code that actually gives the participant purpose.
    /// If you need to pass in any arguments, please add them to the
    /// subcommand, and pass that in here. Do not pass them in individually.
    void run();
};

