# GenesisEngine
A voxel engien I am writing in my free time as a hobby project.

## Project Structure
- GenesisCore: The core of the engine. Contains shared server and client engine code.
- GenesisClient: The client part of the engine. Mostly contains rendering stuff.
- GenesisServer: The server part of the engine. Contains utilities for dedicated servers.
- GenesisEditor: The editor project to create games. Might not be included in the engine but time will tell.
- RuntimeCore: Contains logic like loading level files that is both required by the server and the client when acutally running a game.
- RuntimeClient: Contains logic and startup code to start a client.
- RuntimeServer: Contians logic and startup code to start a dedicated server.
