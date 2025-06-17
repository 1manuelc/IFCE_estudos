export enum EmployeePositions {
	DESENVOLVEDOR = 'DESENVOLVEDOR',
	DBA = 'DBA',
	TESTADOR = 'TESTADOR',
	GERENTE = 'GERENTE',
}

export type EmployeeType = {
	name: string;
	base_salary_in_reais: number;
	position: EmployeePositions;
};

export class Employee {
	private name: string;
	private base_salary_in_reais: number;
	private position: EmployeePositions;

	constructor(
		name: string,
		base_salary_in_reais: number,
		position: EmployeePositions
	) {
		this.name = name;
		this.base_salary_in_reais = base_salary_in_reais;
		this.position = position;
	}

	public getName() {
		return this.name;
	}

	public setName(name: string) {
		this.name = name;
		console.log(`Name: "${name}" set sucessfully`);
	}

	public getBaseSalary() {
		return this.base_salary_in_reais;
	}

	public setBaseSalary(baseSalaryInReais: number) {
		this.base_salary_in_reais = baseSalaryInReais;
		console.log(
			`New base salary: R$ ${baseSalaryInReais.toFixed(2)} set sucessfully`
		);
	}

	public getPosition() {
		return this.position;
	}

	public setPosition(position: EmployeePositions) {
		this.position = position;
		console.log(`New position: "${position}" set sucessfully`);
	}
}
