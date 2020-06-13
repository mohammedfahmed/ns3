
Classname::static function name()
namespace::function name(), name space is a module (a file) that collects a group of functions
class_instance.function name (not static function)
pointer_to_a_class_instance -> function name (not static function)
 

NS_LOG_COMPONENT_DEFINE ("a-LTE-Network"); 

> Define logging component 
> text file in the ns3 root
>  NS_LOG, NS3_LOG_ENABLE,  LogComponentEnable


void PrintRoutingTable (Ptr<Ipv4StaticRouting>);

static void  PingRtt (std::string context, Time rtt)
{
NS_LOG_UNCOND ("Received Response with RTT = " << rtt);
}

//Trace Ping
Config::Connect ("/Names/app/Rtt", MakeCallback (&PingRtt));

void PrintRoutingTable (Ptr<Ipv4StaticRouting> routing) {
for (uint16_t i = 0; i < routing->GetNRoutes (); i++) {
	cout << routing->GetRoute (i) << endl;
}


int main (int argc, char *argv[]){

> argc count
> argv values

LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);


ConfigStore inputConfig;
inputConfig.ConfigureDefaults ();

> Class::static_function (sometimes we define classes just to collect all utility functions)
Config::SetDefault ("ns3::LteHelper::UseCa", BooleanValue (useCa));


//We use LTE helper to create the architecture
> smart pointers are created using 'CreateObject<LteHelper> ();' instead of new keyword in raw pointers
> pointer template name <Class name> instance name =  CreateObject<Class Name> ();  
> [CreateObject] creates an object of class LteHelper and returns a pointer to it
> Ptr<T> ns3::CreateObject 	(Args &&...args) 	
> Create an object by type, with varying number of constructor parameters. 
> return an object of type Ptr<T> whcih encapsulates a pinter to an object of the the type T
> [Ptr] ns3::Ptr< T > Class Template Reference
> Class vs Class Template
>>>> Ptr<LteHelper> lteHelper = CreateObject<LteHelper> ();  

//Create a point-to-point EPC helper to attach to the created EPC helper
Ptr<PointToPointEpcHelper> epcHelper = CreateObject<PointToPointEpcHelper> ();
pionter to the object -> arrow notation to access function 
lteHelper->SetEpcHelper (epcHelper);

//Create pgw node and install the created poin-to-point EPC on it
>>>> Ptr<Node> pgw = epcHelper->GetPgwNode ();

//Create a remote host to provide user with service 
> object instansiation
NodeContainer remoteHostContainer;
> populate the object (calls the class constructor)
remoteHostContainer.Create (1);

>>>> Ptr<Node> remoteHost = remoteHostContainer.Get (0);


InternetStackHelper internet;
internet.Install (remoteHostContainer);


//Static routing 
Ipv4StaticRoutingHelper ipv4RoutingHelper;
> nested call (return a pointer to an anonymose object of the type IPv4 of remotehost )
Ptr<Ipv4StaticRouting> remoteHostStaticRouting = ipv4RoutingHelper.GetStaticRouting (remoteHost->GetObject<Ipv4> ());


// Install Mobility Model
Ptr<ListPositionAllocator> positionAlloc = CreateObject<ListPositionAllocator> ();
for (uint16_t i = 0; i < numNodePairs; i++)
  {
    positionAlloc->Add (Vector (distance * i, 0, 0));
  }
MobilityHelper mobility;
mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
mobility.SetPositionAllocator(positionAlloc);
mobility.Install(enbNodes);
mobility.Install(ueNodes);

// Install LTE Devices to the nodes
NetDeviceContainer enbLteDevs = lteHelper->InstallEnbDevice (enbNodes);
NetDeviceContainer ueLteDevs = lteHelper->InstallUeDevice (ueNodes);

// Install the IP stack on the UEs
internet.Install (ueNodes);
Ipv4InterfaceContainer ueIpIface;
ueIpIface = epcHelper->AssignUeIpv4Address (NetDeviceContainer (ueLteDevs));
// Assign IP address to UEs, and install applications
for (uint32_t u = 0; u < ueNodes.GetN (); ++u)
{
  Ptr<Node> ueNode = ueNodes.Get (u);
// Set the default gateway for the UE
  Ptr<Ipv4StaticRouting> ueStaticRouting = ipv4RoutingHelper.GetStaticRouting (ueNode->GetObject<Ipv4> ());
  ueStaticRouting->SetDefaultRoute (epcHelper->GetUeDefaultGatewayAddress (), 1);
}

// Attach one UE per eNodeB
for (uint16_t i = 0; i < numNodePairs; i++)
{
  lteHelper->Attach (ueLteDevs.Get(i), enbLteDevs.Get(i));
}




serverApps.Start (MilliSeconds (500));
clientApps.Start (MilliSeconds (500));
lteHelper->EnableTraces ();
p2ph.EnablePcapAll("LTE-network-test");



Simulator::Stop (simTime);
Simulator::Run ();
Simulator::Destroy ();
return 0;
}
