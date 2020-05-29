# Key Abstractions

## Node:
- In ns-3 the basic computing device abstraction is called the node. 
- The Node class provides methods for managing the representations of computing devices in simulations.

## Application 
Examples: UdpEchoClientApplication, UdpEchoServerApplication

## Channel 
Examples: CsmaChannel(Ethernet-like), PointToPointChannel, WifiChannel

## NetDevice 
Examples: CsmaNetDevice, PointToPointNetDevice, WifiNetDevice
- Network devices (NICs) are controlled using network device drivers collectively known as net devices. 
- In Unix and Linux you refer to these net devices by names such as eth0. In ns-3 the net device abstraction covers both the software driver and the simulated hardware.
- The CsmaNetDevice is designed to work with a CsmaChannel; the PointToPointNetDevice is designed to work with a PointToPointChannel and a WifiNetNevice is designed to work with a WifiChannel.

## Topology Helpers: