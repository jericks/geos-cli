#include "GeosCli/BufferCommand.hpp"

BufferCommand::BufferCommand(CLI::App* app): Command ("buffer", "Buffer a geometry") {
    CLI::App* cmd = app->add_subcommand(this->getName(), this->getDescription());
    cmd->add_option("-g", options.geometry, "Geometry");
    cmd->add_option("-d", options.distance, "Distance")->required();
}

void BufferCommand::execute(std::istream& istream, std::ostream& ostream) {
    if (options.geometry.empty()) {
        std::getline(istream, options.geometry);
    }
    geos::io::WKTReader reader;
    auto geometry = reader.read(options.geometry);
    geos::io::WKTWriter writer;
    auto buffer = geometry->buffer(options.distance, 10);
    auto wkt = writer.write(buffer.get());
    ostream << wkt << std::endl;
}