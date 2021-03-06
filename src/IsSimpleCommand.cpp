#include "GeosCli/IsSimpleCommand.hpp"

IsSimpleCommand::IsSimpleCommand(CLI::App* app): Command ("issimple", "Determine if a geometry is simple") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
}

void IsSimpleCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    bool isSimple = geometry.get()->isSimple();
    ostream << (isSimple ? "true" : "false") << std::endl;
}