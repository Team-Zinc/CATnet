/// \breif Registrar class that contains all the data needed for runtime in case of registrar mode.
class Registrar {
public:
    /// \breif Constructor for the registrar.
    /// If you need to pass in any arguments, please add them to the
    /// subcommand, and pass that in here. Do not pass them in individually.
    Registrar();

    /// \breif Destructor for the registrar.
    ~Registrar();
    
    /// \breif Run the main code that actually gives the registrar purpose.
    /// If you need to pass in any arguments, please add them to the
    /// subcommand, and pass that in here. Do not pass them in individually.
    void run();
};

