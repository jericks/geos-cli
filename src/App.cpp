#include <iostream>
#include "GeosCli/GeosCli.hpp"
#include "CLI11.hpp"

int main(int argc, char const *argv[]) {

    CLI::App app{"GEOS CLI"};
    app.require_subcommand(1);

    Commands commands;
    AreaCommand areaCommand(&app);
    commands.add(&areaCommand);
    BoundaryCommand boundaryCommand(&app);
    commands.add(&boundaryCommand);
    BufferCommand bufferCommand(&app);
    commands.add(&bufferCommand);
    CentroidCommand centroidCommand(&app);
    commands.add(&centroidCommand);
    ContainsCommand containsCommand(&app);
    commands.add(&containsCommand);
    ConvexHullCommand convexHullCommand(&app);
    commands.add(&convexHullCommand);
    CountCommand countCommand(&app);
    commands.add(&countCommand);
    CountPointsCommand countPointsCommand(&app);
    commands.add(&countPointsCommand);
    DelaunayTriangulationCommand delaunayTriangulationCommand(&app);
    commands.add(&delaunayTriangulationCommand);
    DistanceCommand distanceCommand(&app);
    commands.add(&distanceCommand);
    EnvelopeCommand envelopeCommand(&app);
    commands.add(&envelopeCommand);
    InteriorPointCommand interiorPointCommand(&app);
    commands.add(&interiorPointCommand);
    IntersectsCommand intersectsCommand(&app);
    commands.add(&intersectsCommand);
    IsWithinDistanceCommand isWithinDistanceCommand(&app);
    commands.add(&isWithinDistanceCommand);
    LengthCommand lengthCommand(&app);
    commands.add(&lengthCommand);
    ListCommand listCommand(&app, &commands);
    commands.add(&listCommand);
    VoronoiDiagramCommand voronoiDiagramCommand(&app);
    commands.add(&voronoiDiagramCommand);
    WithinCommand withinCommand(&app);
    commands.add(&withinCommand);

    CLI11_PARSE(app, argc, argv);

    for(Command* cmd : commands.get()) {
      if (app.got_subcommand(cmd->getName())) {
        cmd->execute(std::cin, std::cout);
        break;
      }
    }

    return 0;
}
