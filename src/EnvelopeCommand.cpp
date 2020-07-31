#include "GeosCli/EnvelopeCommand.hpp"

EnvelopeCommand::EnvelopeCommand(CLI::App* app): Command ("envelope") {
    CLI::App* cmd = app->add_subcommand("envelope", "Get the envelope from a geometry");
    cmd->add_option("-g", options.geometry, "Parameter");
}

void EnvelopeCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    GEOSGeometry* geom = GEOSGeomFromWKT(options.geometry.c_str());
    GEOSGeometry* outGeom = GEOSEnvelope(geom);
    char* wkt = GEOSGeomToWKT(outGeom); 
    GEOSGeom_destroy(geom);
    GEOSGeom_destroy(outGeom);
    ostream << wkt << std::endl;
}