#include "GeosCli/ConvexHullCommand.hpp"

ConvexHullCommand::ConvexHullCommand(CLI::App* app): Command ("convexhull") {
    CLI::App* cmd = app->add_subcommand("convexhull", "Get the convexhull of a geometry");
    cmd->add_option("-g", options.geometry, "Parameter");
}

void ConvexHullCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    GEOSGeometry* geom = GEOSGeomFromWKT(options.geometry.c_str());
    GEOSGeometry* outGeom = GEOSConvexHull(geom);
    char* wkt = GEOSGeomToWKT(outGeom); 
    GEOSGeom_destroy(geom);
    GEOSGeom_destroy(outGeom);
    ostream << wkt << std::endl;
}