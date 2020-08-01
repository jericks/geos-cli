#include "GeosCli/CentroidCommand.hpp"

CentroidCommand::CentroidCommand(CLI::App* app): Command ("centroid") {
    CLI::App* cmd = app->add_subcommand("centroid", "Get the centroid from a geometry");
    cmd->add_option("-g", options.geometry, "Geometry");
}

void CentroidCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto centroid = geometry->getCentroid();
    auto wkt = writer.write(centroid.get());
    ostream << wkt << std::endl;
}