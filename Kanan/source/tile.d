// MIT-License https://github.com/higashi000/procon30-kyogi
module Kanan.tile;

struct Tile {
  import Kanan.agent;
  import Kanan.color;

  Agent agent = Agent.Null;
  Color color = Color.White;
  int tilePoint;
}
