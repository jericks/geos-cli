#include "GeosCli/CentroidCommand.hpp"

CentroidCommand::CentroidCommand(CLI::App* app): Command ("centroid", "Get the centroid from a geometry") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
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