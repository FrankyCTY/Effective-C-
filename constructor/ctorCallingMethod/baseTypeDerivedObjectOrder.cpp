#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "========= Called by parent constructor =========" << endl;
		cout << "Parent CTOR" << endl;
		NormalOperation();
		VirtualOperation();
		// OperationOverriddenByChild();
	}

	void NormalOperation()
	{
		cout << "Parent calls normal operation" << endl;
	}

	virtual void OperationOverriddenByChild() = 0;

	virtual void VirtualOperation()
	{
		cout << "Parent calls virtual operation" << endl;
	};
};

class Child : public Parent
{
public:
	Child()
	{
		cout << "\n========= Called by child constructor =========" << endl;
		cout << "Child CTOR" << endl;
		NormalOperation();
		VirtualOperation();
		OperationOverriddenByChild();
	}

	void NormalOperation()
	{
		cout << "Child calls normal operation" << endl;
	}

	void OperationOverriddenByChild() override
	{
		cout << "Child calls overridden operation" << endl;
	};

	void VirtualOperation()
	{
		cout << "Child calls virtual operation" << endl;
	};
};

int main()
{
	Parent *child = new Child();
	cout << "\n========= Normal method calls =========" << endl;

	child->NormalOperation();
	child->VirtualOperation();
	child->OperationOverriddenByChild();

	delete child;
	return 0;
};

// ========= Called by parent constructor =========
// Parent CTOR
// Parent calls normal operation
// Parent calls virtual operation

// ========= Called by child constructor =========
// Child CTOR
// Child calls normal operation
// Child calls virtual operation
// Child calls overridden operation

// ========= Normal method calls =========
// Parent calls normal operation
// Child calls virtual operation
// Child calls overridden operation