#include "qkd-app-qos.h"
#include "ns3/log.h"
#include "ns3/simulator.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("QKDAppQoS");
NS_OBJECT_ENSURE_REGISTERED (QKDAppQoS);

TypeId
QKDAppQoS::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::QKDAppQoS")
    .SetParent<QKDApp014> ()
    .SetGroupName ("Applications")
    .AddConstructor<QKDAppQoS> ();
  return tid;
}

QKDAppQoS::QKDAppQoS ()
{
  NS_LOG_FUNCTION (this);
}

QKDAppQoS::~QKDAppQoS ()
{
  NS_LOG_FUNCTION (this);
}

void
QKDAppQoS::ScheduleTx ()
{
  NS_LOG_FUNCTION (this);

  // Ellenőrizzük, hogy még van-e mit küldeni
  if (m_packetsSent >= m_numberOfKeysKMS)
    {
      NS_LOG_INFO ("QKDAppQoS: All packets sent, stopping transmission.");
      return;
    }

  // QoS alapú ütemezés: gyorsabb, ha nagyobb a sávszél
  double qosFactor = (m_dataRate.GetBitRate () > 1e6) ? 0.7 : 1.5;

  // Következő küldés időzítése
  Time nextTime = Seconds ((m_packetSize * 8) / (m_dataRate.GetBitRate () * qosFactor));

  NS_LOG_INFO ("QKDAppQoS: Scheduling QoS packet in "
               << nextTime.GetSeconds () << " seconds.");

  // Az ősosztály SendPacket() metódusát használjuk a tényleges küldéshez
  m_sendEvent = Simulator::Schedule (nextTime, &QKDAppQoS::SendPacket, this);

  // Növeljük a számlálót
  m_packetsSent++;
}

} // namespace ns3

