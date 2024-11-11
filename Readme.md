## Milanote link

## Server diagram link

https://lucid.app/lucidchart/eb01e4ea-2e7c-4e0d-a901-c52791bffc05/edit?invitationId=inv_2b347090-624a-4db4-af24-b1fe696d669f&page=0_0#

## Client diagram link

https://lucid.app/lucidchart/f8cad297-d940-4ca0-a8fc-29c7bc30e35b/edit?invitationId=inv_7934f63b-7bb6-463d-85b9-53f2999eb371&page=0_0#

## Protocol

Client -> Server

1 email password -> login(); Connection
2                -> disconnect(); Disconnection
3 x y z rotx     -> move(); Move the player

Server -> Client

1 id x y z      -> NewConnection(); Retour de la demande de connection du client
2 id x y z      -> OtherPlayerConnection(); Connexion of an other player on the scene
3 id            -> OtherPlayerDisconnection(); Disconnexion of a player on the scene
4 id x y z rotx -> OtherPlayerMove(); Move of a player on the scene
5               -> PlayerNotFound(); Player not found in database