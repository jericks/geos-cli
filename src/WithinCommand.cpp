#include "GeosCli/WithinCommand.hpp"

WithinCommand::WithinCommand(CLI::App* app): Command ("within") {
    CLI::App* cmd = app->add_subcommand("within", "Determine if one geometry is within another");
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void WithinCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    bool contains = geometry.get()->within(otherGeometry.get());
    ostream << (contains ? "true" : "false") << std::endl;
}