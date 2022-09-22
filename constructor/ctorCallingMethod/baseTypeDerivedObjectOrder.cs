abstract class Parent
{
	public Parent()
	{
		System.Console.WriteLine("========= Called by parent constructor =========");
		Console.WriteLine("Parent CTOR");
		NormalOperation();
		VirtualOperation();
		OperationOverriddenByChild();
	}

	public void NormalOperation()
	{
		Console.WriteLine("Parent calls normal operation");
	}

	abstract public void OperationOverriddenByChild();
	virtual public void VirtualOperation()
	{
		System.Console.WriteLine("Parent calls virtual operation");
	}
}

class Child : Parent
{
	public Child()
	{
		System.Console.WriteLine("\n========= Called by child constructor =========");
		Console.WriteLine("Child CTOR");
		NormalOperation();
		VirtualOperation();
		OperationOverriddenByChild();
	}

	public new void NormalOperation()
	{
		Console.WriteLine("Child calls normal operation");
	}

	override public void OperationOverriddenByChild()
	{
		Console.WriteLine("Child calls overridden operation");
	}

	override public void VirtualOperation()
	{
		System.Console.WriteLine("Child calls virtual operation");
	}
}

namespace baseTypeDerivedObjectOrder
{

	class Program
	{
		static void Main(string[] args)
		{
			Parent child = new Child();
			System.Console.WriteLine("\n========= Normal method calls =========");
			child.NormalOperation();
			child.VirtualOperation();
			child.OperationOverriddenByChild();
		}
	}
}

// ========= Called by parent constructor =========
// Parent CTOR
// Parent calls normal operation
// Child calls virtual operation
// Child calls overridden operation

// ========= Called by child constructor =========
// Child CTOR
// Child calls normal operation
// Child calls virtual operation
// Child calls overridden operation

// ========= Normal method calls =========
// Parent calls normal operation
// Child calls virtual operation
// Child calls overridden operation

