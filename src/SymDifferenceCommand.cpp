#include "GeosCli/SymDifferenceCommand.hpp"

SymDifferenceCommand::SymDifferenceCommand(CLI::App* app): Command ("symdifference") {
    CLI::App* cmd = app->add_subcommand("symdifference", "Calculate the symdifference between two geometries");
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-o", options.otherGeometry, "Other Geometry")->required();
}

void SymDifferenceCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    auto otherGeometry = reader.read(options.otherGeometry);
    geos::io::WKTWriter writer;
    auto symdifference = geometry->symDifference(otherGeometry.get());
    auto wkt = writer.write(symdifference.get());
    ostream << wkt << std::endl;
}