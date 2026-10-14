#include "BlackjackCard.h"

int BlackjackCard::Value() const
{
    if (face_ == CardFace::Jack or 
        face_ == CardFace::Queen or 
        face_ == CardFace::King)
        return 10;
    return face_;
}
