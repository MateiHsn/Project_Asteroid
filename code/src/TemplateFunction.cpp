#include "../headers/DefaultParameters.hpp"

template <class T>
bool StillInWindow ( T Obj ) {

  int top_dist = Obj.GetPos ( ).y;
  int bottom_dist = DefaultParameters::GetInstance()->GetRenderHeight() - Obj.GetPos ( ).y;

  int left_dist = Obj.GetPos ( ).x;
  int right_dist = DefaultParameters::GetInstance ( )->GetRenderWidth ( ) - Obj.GetPos ( ).x;

  if ( top_dist < 0 || bottom_dist < 0 || left_dist < 0 || right_dist < 0 ) return false;

  return true;

}
