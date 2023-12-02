package service.serviceImpl;

import dao.CompanyDao;
import dao.daoImpl.CompanyDaoImpl;
import entity.Company;
import exception.ShowException;
import org.hibernate.HibernateError;
import service.CompanyService;

import java.util.List;

public class CompanyServiceImpl implements CompanyService {

    CompanyDao companyDao = new CompanyDaoImpl();

    public CompanyServiceImpl() {}

    @Override
    public boolean addCompany(Company company) {
        boolean isAdded = false;
        try {
            companyDao.addCompany(company);
            isAdded = true;
        }
        catch (HibernateError e) {
            ShowException.showNotice(e);
        }
        return isAdded;
    }

    @Override
    public boolean updateCompany(Company company) {
        boolean isUpdated = false;
        try
        {
            isUpdated = companyDao.updateCompany(company);
        }
        catch(Exception e)
        {
            ShowException.showNotice(e);
        }
        //System.out.println("Это ДЗ");
        return isUpdated;
    }

    @Override
    public boolean deleteCompany(int id) {
        //System.out.println("Это ДЗ");
        boolean isDeleted = false;
        try
        {
            isDeleted = companyDao.deleteCompany(id);
        }
        catch(Exception e)
        {
            ShowException.showNotice(e);
        }
        return isDeleted;
        //return false;
    }

    @Override
    public List<Company> showCompanies() {
        //System.out.println("Это ДЗ");
        List<Company> companies = null;
        try
        {
            companies = companyDao.showCompanies();
        }
        catch(Exception e)
        {
            ShowException.showNotice(e);
        }
        return companies;
        //return null;
    }

    @Override
    public Company findCompanyById(int id) {
        //System.out.println("Это ДЗ");
        Company company = null;
        try
        {
            company = companyDao.findCompanyById(id);
        }
        catch(Exception e)
        {
            ShowException.showNotice(e);
        }
        return company;
        //return null;
    }

    @Override
    public Company findCompanyByName(String name) {
        Company company = null;
        try
        {
            company = companyDao.findCompanyByName(name);
        }
        catch(Exception e)
        {
            ShowException.showNotice(e);
        }
        return company;
        //System.out.println("Это ДЗ");
      //  return company;
        //return null;
    }
}
