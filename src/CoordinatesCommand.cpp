#include "GeosCli/CoordinatesCommand.hpp"

CoordinatesCommand::CoordinatesCommand(CLI::App* app): Command ("coordinates") {
    CLI::App* cmd = app->add_subcommand("coordinates", "Get the coordinates of a geometry");
    cmd->add_option("-g", options.geometry, "Geometry");
}

void CoordinatesCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto factory = geometry->getFactory();
    auto coordinateSequence = geometry->getCoordinates();
    std::vector<geos::geom::Coordinate> coordinates;
    coordinateSequence->toVector(coordinates);
    auto multiPoint = factory->createMultiPoint(coordinates);
    auto wkt = writer.write(multiPoint);
    ostream << wkt << std::endl;
}