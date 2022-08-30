#include "GeosCli/ConcaveHullCommand.hpp"

ConcaveHullCommand::ConcaveHullCommand(CLI::App* app): Command ("concavehull", "Get the concavehull of a geometry") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-l", options.length, "Length");
}

void ConcaveHullCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto convexHull = geos::algorithm::hull::ConcaveHull::concaveHullByLength(geometry.get(), options.length, true);
    auto wkt = writer.write(convexHull.get());
    ostream << wkt << std::endl;
}