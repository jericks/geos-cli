#include "GeosCli/BufferCommand.hpp"

BufferCommand::BufferCommand(CLI::App* app): Command ("buffer") {
    CLI::App* cmd = app->add_subcommand("buffer", "Buffer a geometry");
    cmd->add_option("-g", options.geometry, "Parameter");
    cmd->add_option("-d", options.distance, "Parameter");
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