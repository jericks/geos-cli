#include "GeosCli/BufferCommand.hpp"

BufferCommand::BufferCommand(CLI::App* app): Command ("buffer") {
    CLI::App* cmd = app->add_subcommand("buffer", "Buffer a geometry");
    cmd->add_option("-g", options.geometry, "Parameter");
    cmd->add_option("-d", options.distance, "Parameter");
}

void BufferCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    GEOSGeometry* geom = GEOSGeomFromWKT(options.geometry.c_str());
    GEOSGeometry* bufferGeom = GEOSBuffer(geom, options.distance, 8);
    char* wkt = GEOSGeomToWKT(bufferGeom); 
    GEOSGeom_destroy(geom);
    GEOSGeom_destroy(bufferGeom);
    ostream << wkt << std::endl;
}