#include "GeosCli/EnvelopeCommand.hpp"

EnvelopeCommand::EnvelopeCommand(CLI::App* app): Command ("envelope", "Get the envelope from a geometry") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Input Geometry");
}

void EnvelopeCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto envelope = geometry->getEnvelope();
    auto wkt = writer.write(envelope.get());
    ostream << wkt << std::endl;
}