#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"

int main(int argc, char const *argv[]) {

    CLI::App app{"GEOS CLI"};
    app.require_subcommand(1);

    Commands commands;
    AreaCommand areaCommand(&app);
    commands.add(&areaCommand);
    BufferCommand bufferCommand(&app);
    commands.add(&bufferCommand);
    CentroidCommand centroidCommand(&app);
    commands.add(&centroidCommand);
    ConvexHullCommand convexHullCommand(&app);
    commands.add(&convexHullCommand);
    DelaunayTriangulationCommand delaunayTriangulationCommand(&app);
    commands.add(&delaunayTriangulationCommand);
    EnvelopeCommand envelopeCommand(&app);
    commands.add(&envelopeCommand);
    InteriorPointCommand interiorPointCommand(&app);
    commands.add(&interiorPointCommand);
    ListCommand listCommand(&app, &commands);
    commands.add(&listCommand);
    VoronoiDiagramCommand voronoiDiagramCommand(&app);
    commands.add(&voronoiDiagramCommand);

    CLI11_PARSE(app, argc, argv);

    for(Command* cmd : commands.get()) {
      if (app.got_subcommand(cmd->getName())) {
        cmd->execute(std::cin, std::cout);
        break;
      }
    }

    return 0;
}
