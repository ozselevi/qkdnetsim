#ifndef QKD_APP_QOS_H
#define QKD_APP_QOS_H

#include "ns3/qkd-app-014.h"

namespace ns3 {

/**
 * \ingroup applications
 * \brief A QKD alkalmazás, ami a QKDApp014-ből származik,
 * de egyedi QoS-alapú ütemezési logikával rendelkezik.
 */
class QKDAppQoS : public QKDApp014
{
public:
  /**
   * Statikus metódus az ns-3 TypeId rendszer regisztrációjához.
   * Minden ns-3 objektumnak rendelkeznie kell vele.
   * \return Az osztály egyedi TypeId-je.
   */
  static TypeId GetTypeId ();

  QKDAppQoS ();
  virtual ~QKDAppQoS ();

protected:
  // A ScheduleTX függvényt felülírjuk (override).
  // Ezzel a metódusban a QKDAppQoS egyedi logikáját tudjuk megvalósítani.
  virtual void ScheduleTx () override;

};

} // namespace ns3

#endif /* QKD_APP_QOS_H */
