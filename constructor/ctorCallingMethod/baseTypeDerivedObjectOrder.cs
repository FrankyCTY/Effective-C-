using System;

class Parent
{
	public Parent()
	{
		Console.WriteLine("Parent CTOR");
		Test();
	}

	virtual public void SayHi()
	{
		Console.WriteLine("Parent Said Hi");
	}

	virtual public void Test()
	{
		Console.WriteLine("Parent Test");
	}
}

class Child : Parent
{
	public Child()
	{
		Console.WriteLine("Child CTOR");
		Test();
	}

	override public void SayHi()
	{
		Console.WriteLine("Child Said Hi");
	}

	override public void Test()
	{
		Console.WriteLine("Child Test");
	}
}

namespace testCsharp
{

	class Program
	{
		static void Main(string[] args)
		{
			Parent child = new Child();
			child.SayHi();
		}
	}
}

// Parent CTOR
// Child Test
// Child CTOR
// Child Test
// Child Said Hi