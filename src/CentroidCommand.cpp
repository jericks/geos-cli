#include "GeosCli/CentroidCommand.hpp"

CentroidCommand::CentroidCommand(CLI::App* app): Command ("centroid") {
    CLI::App* cmd = app->add_subcommand("centroid", "Get the centroid from a geometry");
    cmd->add_option("-g", options.geometry, "Parameter");
}

void CentroidCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    GEOSGeometry* geom = GEOSGeomFromWKT(options.geometry.c_str());
    GEOSGeometry* centroidGeom = GEOSGetCentroid(geom);
    char* wkt = GEOSGeomToWKT(centroidGeom); 
    GEOSGeom_destroy(geom);
    GEOSGeom_destroy(centroidGeom);
    ostream << wkt << std::endl;
}