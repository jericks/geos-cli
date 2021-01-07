#include "GeosCli/DisjointCommand.hpp"

DisjointCommand::DisjointCommand(CLI::App* app): Command ("disjoint", "Determine whether a geometry is disjoint from another") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void DisjointCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    auto disjoint = geometry->disjoint(otherGeometry.get());
    ostream << (disjoint ? "true" : "false") << std::endl;
}