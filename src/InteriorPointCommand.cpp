#include "GeosCli/InteriorPointCommand.hpp"

InteriorPointCommand::InteriorPointCommand(CLI::App* app): Command ("interiorpoint") {
    CLI::App* cmd = app->add_subcommand("interiorpoint", "Get the interior point from a geometry");
    cmd->add_option("-g", options.geometry, "Parameter");
}

void InteriorPointCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    GEOSGeometry* geom = GEOSGeomFromWKT(options.geometry.c_str());
    GEOSGeometry* outGeom = GEOSPointOnSurface(geom);
    char* wkt = GEOSGeomToWKT(outGeom); 
    GEOSGeom_destroy(geom);
    GEOSGeom_destroy(outGeom);
    ostream << wkt << std::endl;
    ostream << wkt << std::endl;
}