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
    CoordinatesCommand coordinatesCommand(&app);
    commands.add(&coordinatesCommand);
    CountCommand countCommand(&app);
    commands.add(&countCommand);
    CountPointsCommand countPointsCommand(&app);
    commands.add(&countPointsCommand);
    CoversCommand coversCommand(&app);
    commands.add(&coversCommand);
    CoveredByCommand coveredByCommand(&app);
    commands.add(&coveredByCommand);
    CrossesCommand crossesCommand(&app);
    commands.add(&crossesCommand);
    DelaunayTriangulationCommand delaunayTriangulationCommand(&app);
    commands.add(&delaunayTriangulationCommand);
    DifferenceCommand differenceCommand(&app);
    commands.add(&differenceCommand);
    DisjointCommand disjointCommand(&app);
    commands.add(&disjointCommand);
    DistanceCommand distanceCommand(&app);
    commands.add(&distanceCommand);
    EnvelopeCommand envelopeCommand(&app);
    commands.add(&envelopeCommand);
    GetCommand getCommand(&app);
    commands.add(&getCommand);
    InteriorPointCommand interiorPointCommand(&app);
    commands.add(&interiorPointCommand);
    IntersectionCommand intersectionCommand(&app);
    commands.add(&intersectionCommand);
    IntersectsCommand intersectsCommand(&app);
    commands.add(&intersectsCommand);
    IsEmptyCommand isEmptyCommand(&app);
    commands.add(&isEmptyCommand);
    IsRectCommand isRectCommand(&app);
    commands.add(&isRectCommand);
    IsSimpleCommand isSimpleCommand(&app);
    commands.add(&isSimpleCommand);
    IsValidCommand isValidCommand(&app);
    commands.add(&isValidCommand);
    IsWithinDistanceCommand isWithinDistanceCommand(&app);
    commands.add(&isWithinDistanceCommand);
    LengthCommand lengthCommand(&app);
    commands.add(&lengthCommand);
    ListCommand listCommand(&app, &commands);
    commands.add(&listCommand);
    SymDifferenceCommand symDifferenceCommand(&app);
    commands.add(&symDifferenceCommand);
    TouchesCommand touchesCommand(&app);
    commands.add(&touchesCommand);
    TypeCommand typeCommand(&app);
    commands.add(&typeCommand);
    UnionCommand unionCommand(&app);
    commands.add(&unionCommand);
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
