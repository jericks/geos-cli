#include "GeosCli/OffsetCurveCommand.hpp"

OffsetCurveCommand::OffsetCurveCommand(CLI::App* app): Command ("offsetcurve", "Get the offset curve a geometry") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-d", options.distance, "Distance")->required();
}

void OffsetCurveCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    geos::operation::buffer::OffsetCurve offsetCurve {*geometry.get(), options.distance};
    auto curve = offsetCurve.getCurve();
    auto wkt = writer.write(curve.get());
    ostream << wkt << std::endl;
}