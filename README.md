## IOT Ecosystem Simulation - Plane sensors

The project goal is to simulate plane sensors and send their measures to a server, which logs these measures.

### Sensors
This ecosystem generates measures from 4 sensors, of different return types:
- Temperature, Humidity: float
- Light: boolean
- Pressure: int

Each sensor has its own class which inherits from the template class Sensor, the template being used to change the return types f the sensors data.

### Server
The server (Server class) manages the output. It writes the measures values in the log files and in the console.<br/>
The methods which receive and writes the data use templates to adapt to every sensor.

### Scheduler
The scheduler (Scheduler class) manages the data transmission to the server and the data collecting.<br/>
It uses a different thread per sensor, as they have different period of data collecting. These measures are then collected and sent to the server.

### User interaction
The uses can choose if he wants to log in the files and the console at the beginning of the program. He can also choose the duration of the simulation.