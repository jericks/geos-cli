#include "GeosCli/CoveredByCommand.hpp"

CoveredByCommand::CoveredByCommand(CLI::App* app): Command ("coveredby") {
    CLI::App* cmd = app->add_subcommand("coveredby", "Determine if one geometry is coveredby another");
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void CoveredByCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    bool coveredby = geometry.get()->coveredBy(otherGeometry.get());
    ostream << (coveredby ? "true" : "false") << std::endl;
}