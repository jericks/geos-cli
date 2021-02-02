#include "GeosCli/MakeValidCommand.hpp"

MakeValidCommand::MakeValidCommand(CLI::App* app): Command ("makevalid", "Make a geometry valid") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
}

void MakeValidCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto validGeometry = geos::operation::valid::MakeValid().build(geometry.get());
    auto wkt = writer.write(validGeometry.get());
    ostream << wkt << std::endl;
}