#pragma once

#include <string>
#include <iostream>

class Command {

    public:

        Command(std::string name, std::string description);

        std::string getName() const;

        std::string getDescription() const;

        virtual void execute(std::istream& istream, std::ostream& ostream) = 0;

    private:

        std::string name;

        std::string description;

};