#include "GeosCli/VoronoiDiagramCommand.hpp"

VoronoiDiagramCommand::VoronoiDiagramCommand(CLI::App* app): Command ("voronoidiagram", "Create a voronoi diagram") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Input Geometry");
}

void VoronoiDiagramCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    geos::triangulate::VoronoiDiagramBuilder voronoiDiagramBuilder;
    voronoiDiagramBuilder.setSites(*geometry);
    auto diagram = voronoiDiagramBuilder.getDiagram(*geometry->getFactory());
    auto wkt = writer.write(diagram.get());
    ostream << wkt << std::endl;
}