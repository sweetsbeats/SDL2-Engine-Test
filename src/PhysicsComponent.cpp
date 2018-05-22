#include "PhysicsComponent.h"


void PhysicsComponent::update() {

}

void PhysicsComponent::update(Entity* entity) {
  
}


bool PhysicsComponent::isColliding(PhysicsComponent* collidable) {
  if ( (b_box.x + b_box.w) >= collidable->b_box.x ) {
    return true;
  } else if ( b_box.x <= (collidable->b_box.x + collidable->b_box.w ) ) {
    return true;
  } else if ( (b_box.y + b_box.h) >= collidable->b_box.y ) {
    return true;
  } else if ( b_box.y <= (collidable->b_box.y + collidable->b_box.h) ) {
    return true;
  }
 
}

Vec2 PhysicsComponent::getCollisionArea(PhysicsComponent* collidable) {
  
  int32 maxLength;
  int32 currLength;

  int32 maxHeight;
  int32 currHeight;

  //TODO(sweets): Look into using absoloute values + taking negative
  
  // X STUFF
  if ( collidable->x >= 0 ) {
    maxLength = this->w + collidable->w;
    currLength = ( collidable->x + collidable->w ) - ( this->x ) ;
  } else {
    maxLength = this->w + (-collidable->w);
    currLength = ( collidable->x + (-collidable->w)  ) - ( this->x ) ;
  }

  // Y STUFF
  if ( collidable->y >= 0 ) {  
    maxHeight = this->y + collidable->y;
    currHeight = ( collidable->y + collidable ->w ) - (this->y) ;
  } else {
    maxHeight = this->y + (-collidable->y);
    currHeight = ( collidable->y + (-collidable ->w) ) - (this->y) ;
  }

  int32 collArea_X = currLength - maxLength;       //Returns - if colliding from the left
  int32 collArea_Y = currHeight - maxHeight;       //Returns - if colliding from the top


  return Vec2( collArea_X, collArea_Y );    
}


PhysicsComponent::PhysicsComponent( int32 _x, int32 _y, int32 _w, int32 _h ) {
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  
  b_box.x = _x;
  b_box.y = _y;
}

PhysicsComponent::~PhysicsComponent() {
  
}

