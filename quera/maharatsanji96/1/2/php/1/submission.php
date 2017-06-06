<?php
	class MyClass{
		public $name;
		public $age;
		public $height;

		public function __construct($n, $a, $h) {
			$this->name = $n;
			$this->age = $a;
			$this->height = $h;
		}
	}

	function comp($fi, $se) {
		if ($fi->age != $se->age)
			return ($fi->age < $se->age);
		return ($fi->height < $se->height);
	}

	function my_sort($arr) {
		$n = count($arr);
		for ($i = 0; $i < $n; $i++) {
			$best = $i;
			for ($j = $i; $j < $n; $j++)
				if (comp($arr[$j], $arr[$best]))
					$best = $j;
			$tmp = $arr[$i];
			$arr[$i] = $arr[$best];
			$arr[$best] = $tmp;
		}
		return $arr;
	}
