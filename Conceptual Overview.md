# Key Abstractions

## Node:

## Application (UdpEchoClientApplication, UdpEchoServerApplication)

## Channel (CsmaChannel(Ethernet-like), PointToPointChannel, WifiChannel)

##NetDevice (CsmaNetDevice, PointToPointNetDevice, WifiNetDevice)
- Network devices (NICs) are controlled using network device drivers collectively known as net devices. 
- In Unix and Linux you refer to these net devices by names such as eth0. In ns-3 the net device abstraction covers both the software driver and the simulated hardware.
- The CsmaNetDevice is designed to work with a CsmaChannel; the PointToPointNetDevice is designed to work with a PointToPointChannel and a WifiNetNevice is designed to work with a WifiChannel.

## Topology Helpers:
