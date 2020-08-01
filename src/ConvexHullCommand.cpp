#include "GeosCli/ConvexHullCommand.hpp"

ConvexHullCommand::ConvexHullCommand(CLI::App* app): Command ("convexhull") {
    CLI::App* cmd = app->add_subcommand("convexhull", "Get the convexhull of a geometry");
    cmd->add_option("-g", options.geometry, "Geometry");
}

void ConvexHullCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto convexHull = geometry->convexHull();
    auto wkt = writer.write(convexHull.get());
    ostream << wkt << std::endl;
}