import { Employee, EmployeePositions } from './Employee.class';

export class SalaryCalculator {
	public calculateNetSalaryInReais(employee: Employee): number {
		const baseSalary = employee.getBaseSalary();
		const position = employee.getPosition();

		switch (position) {
			case EmployeePositions.DESENVOLVEDOR: {
				return baseSalary >= 13000 ? baseSalary * 0.8 : baseSalary * 0.9;
			}

			case EmployeePositions.DBA: {
				return baseSalary >= 15000 ? baseSalary * 0.75 : baseSalary * 0.85;
			}

			case EmployeePositions.TESTADOR: {
				return baseSalary >= 15000 ? baseSalary * 0.75 : baseSalary * 0.85;
			}

			case EmployeePositions.GERENTE: {
				return baseSalary >= 18000 ? baseSalary * 0.7 : baseSalary * 0.8;
			}

			default: {
				throw new Error(`Unknown position "${position}"`);
			}
		}
	}
}
