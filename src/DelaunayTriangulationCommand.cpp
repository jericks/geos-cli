#include "GeosCli/DelaunayTriangulationCommand.hpp"

DelaunayTriangulationCommand::DelaunayTriangulationCommand(CLI::App* app): Command ("delaunaytriangulation") {
    CLI::App* cmd = app->add_subcommand("delaunaytriangulation", "Create delaunay triangles");
    cmd->add_option("-g", options.geometry, "Input Geometry");
}

void DelaunayTriangulationCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    geos::triangulate::DelaunayTriangulationBuilder delaunayTriangulationBuilder;
    delaunayTriangulationBuilder.setSites(*geometry);
    auto triangles = delaunayTriangulationBuilder.getTriangles(*geometry->getFactory());
    auto wkt = writer.write(triangles.get());
    ostream << wkt << std::endl;
}