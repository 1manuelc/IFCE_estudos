import { Employee, EmployeePositions, EmployeeType } from './Employee.class';
import { SalaryCalculator } from './SalaryCalculator.class';

describe('SalaryCalculator class', () => {
	const salaryCalculator = new SalaryCalculator();

	it('should collect user name, base-salary and role', () => {
		const data: EmployeeType = {
			name: 'José da Silva',
			base_salary_in_reais: 13000,
			position: EmployeePositions.DESENVOLVEDOR,
		};

		const employee = new Employee(
			data.name,
			data.base_salary_in_reais,
			data.position
		);

		expect(employee.getName()).toBe(data.name);
		expect(employee.getBaseSalary()).toBe(data.base_salary_in_reais);
		expect(employee.getPosition()).toBe(data.position);
	});

	describe('Calculate the discount from salary per position', () => {
		describe('Developer salary discount', () => {
			it('should correctly calculate the discount (20%) when salary is equal or greater than R$ 13.000,00', () => {
				const devEmployee = new Employee(
					'Dev One',
					15000,
					EmployeePositions.DESENVOLVEDOR
				);

				const devNetSalary =
					salaryCalculator.calculateNetSalaryInReais(devEmployee);
				expect(devNetSalary).toBe(12000);
			});

			it('should correctly calculate the discount (10%) when salary is less than R$ 13,000.00', () => {
				const devEmployee = new Employee(
					'Dev Two',
					10000,
					EmployeePositions.DESENVOLVEDOR
				);

				const devNetSalary =
					salaryCalculator.calculateNetSalaryInReais(devEmployee);
				expect(devNetSalary).toBe(9000);
			});
		});

		describe('Database Administrator (DBA) salary discount', () => {
			it('should correctly calculate the discount (25%) when salary is equal or greater than R$ 15.000,00', () => {
				const dbaEmployee = new Employee(
					'DBA One',
					15000,
					EmployeePositions.DBA
				);

				const dbaNetSalary =
					salaryCalculator.calculateNetSalaryInReais(dbaEmployee);
				expect(dbaNetSalary).toBe(11250);
			});

			it('should correctly calculate the discount (15%) when salary is less than R$ 15,000.00', () => {
				const dbaEmployee = new Employee(
					'DBA Two',
					12000,
					EmployeePositions.DBA
				);

				const dbaNetSalary =
					salaryCalculator.calculateNetSalaryInReais(dbaEmployee);
				expect(dbaNetSalary).toBe(10200);
			});
		});

		describe('Tester salary discount', () => {
			it('should correctly calculate the discount (25%) when salary is equal or greater than R$ 15.000,00', () => {
				const testerEmployee = new Employee(
					'Tester One',
					16000,
					EmployeePositions.TESTADOR
				);

				const testerNetSalary =
					salaryCalculator.calculateNetSalaryInReais(testerEmployee);
				expect(testerNetSalary).toBe(12000);
			});

			it('should correctly calculate the discount (15%) when salary is less than R$ 15,000.00', () => {
				const testerEmployee = new Employee(
					'Tester Two',
					10000,
					EmployeePositions.TESTADOR
				);

				const testerNetSalary =
					salaryCalculator.calculateNetSalaryInReais(testerEmployee);
				expect(testerNetSalary).toBe(8500);
			});
		});

		describe('Manager salary discount', () => {
			it('should correctly calculate the discount (30%) when salary is equal or greater than R$ 18.000,00', () => {
				const managerEmployee = new Employee(
					'Manager One',
					20000,
					EmployeePositions.GERENTE
				);

				const managerNetSalary =
					salaryCalculator.calculateNetSalaryInReais(managerEmployee);
				expect(managerNetSalary).toBe(14000);
			});

			it('should correctly calculate the discount (20%) when salary is less than R$ 18,000.00', () => {
				const managerEmployee = new Employee(
					'Manager Two',
					15000,
					EmployeePositions.GERENTE
				);

				const managerNetSalary =
					salaryCalculator.calculateNetSalaryInReais(managerEmployee);
				expect(managerNetSalary).toBe(12000);
			});
		});
	});
});
