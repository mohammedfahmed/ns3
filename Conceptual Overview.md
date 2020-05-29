# Key Abstractions

## Node:
- In ns-3 the basic computing device abstraction is called the node. 
- The Node class provides methods for managing the representations of computing devices in simulations.

## Application 
Examples: UdpEchoClientApplication, UdpEchoServerApplication

## Channel 
Examples: CsmaChannel(Ethernet-like), PointToPointChannel, WifiChannel
- A real Ethernet uses CSMA/CD (Carrier Sense Multiple Access with Collision Detection) scheme with exponentially increasing backoff to contend for the shared transmission medium. The ns-3 CSMA device and channel models only a subset of this.

## NetDevice 
Examples: CsmaNetDevice, PointToPointNetDevice, WifiNetDevice
- Network devices (NICs) are controlled using network device drivers collectively known as net devices. 
- In Unix and Linux you refer to these net devices by names such as eth0. In ns-3 the net device abstraction covers both the software driver and the simulated hardware.
- The CsmaNetDevice is designed to work with a CsmaChannel; the PointToPointNetDevice is designed to work with a PointToPointChannel and a WifiNetNevice is designed to work with a WifiChannel.

## Topology Helpers:
- In a large simulated network you will need to arrange many connections between Nodes, NetDevices and Channels.
- Since connecting NetDevices to Nodes, NetDevices to Channels, assigning IP addresses, etc., are such common tasks in ns-3, we provide what we call topology helpers to make this as easy as possible.
- For example, it may take many distinct ns-3 core operations to create a NetDevice, add a MAC address, install that net device on a Node, configure the node’s protocol stack, and then connect the NetDevice to a Channel. 
- Even more operations would be required to connect multiple devices onto multipoint channels and then to connect individual networks together into internetworks. 
- We provide topology helper objects that combine those many distinct operations into an easy to use model for your convenience.


# Eaxamples
## Define variables

```cpp
std::string mode = "UseBridge";
uint16_t noEnbs = 1;
Time simTime = Seconds(600);
double distance = 60.0;
string pingTarget ("10.1.1.4");
Time interPacketInterval = MilliSeconds(100);
bool disablePl=false; 
```

## Command Line
```cpp
CommandLine cmd;
GlobalValue::Bind ("SimulatorImplementationType", StringValue ("ns3::RealtimeSimulatorImpl"));
cmd.AddValue("noEnbs","Number of eNodeBs", noEnbs);
cmd.AddValue ("simTime", "Total duration of the simulation", simTime);
cmd.Parse (argc,argv);
```

