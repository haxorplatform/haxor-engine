package js;

@:native("Stats")
extern class Stats {
    public var domElement : js.html.Element;
    public function new() : Void;
    public function setMode(m:Int) : Void;
    public function begin() : Void;
    public function end() : Void;
    public function update() : Void;
}
